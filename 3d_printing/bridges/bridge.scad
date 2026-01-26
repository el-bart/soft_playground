w1 = 30;
w2 = 60;
h = 3;

for(w=[50])
{
  translate([0, w, 0])
  {
    for(dx=[0, w])
      translate([dx, 0, 0])
        cube([5, 10, h]);
    translate([0, 0, h])
      cube([5+w, 10, 2]);
  }
}
