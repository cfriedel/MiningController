difference(){
    // plate
    translate ([55,104.5,-3]) cube([90,98,3],true);
    translate ([18,63,-25]) cylinder(50,d=4.2,true,$fn=100);
    translate ([18,146,-25]) cylinder(50,d=4.2,true,$fn=100);
    translate ([92,63,-25]) cylinder(50,d=4.2,true,$fn=100);
    translate ([92,146,-25]) cylinder(50,d=4.2,true,$fn=100);
}
