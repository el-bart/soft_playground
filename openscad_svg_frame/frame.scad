eps = 0.01;
wall = 2;
wall_h = 4;
spacing = 1;

module model_import(file)
{
  offset(eps)
    import(file);
}

module shape_placeholder()
{
  linear_extrude(2*wall)
    model_import("random_shape.svg");
}

module model_slot_base(name)
{
  module extended_base(r)
  {
    minkowski()
    {
      model_import(name);
      circle(r);
    }
  }

  module frame(wall)
  {
    difference()
    {
      extended_base(spacing + wall/2 + 0.5);
      extended_base(spacing + wall/2);
    }
  }

  module cut_in_frame()
  {
    difference()
    {
      // model
      frame(wall);
      // side wall cuts
      children();
    }
  }

  cut_in_frame()
    children();
}

module model_slot(name)
{
  intersection()
  {
    minkowski()
    {
      linear_extrude(wall_h)
        model_slot_base(name)
          children();
      sphere(r=wall/2);
    }
    // cut-off for the bottom roundings
    // we're only interested in the top of the model
    translate([-50, -50, 0])
      cube(300*[1,1,1]);
  }
}

%shape_placeholder();
model_slot("random_shape.svg")
{
  // some location(s) that shall be removed from the overall shape:
  // bottom
  translate([40, -10, 0])
    square([60, 20]);
  // top
  translate([60, 110, 0])
    square([50, 20]);
}
