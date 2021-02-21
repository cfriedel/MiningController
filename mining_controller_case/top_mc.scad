difference(){
    // plate
    cube([110,160,2],false);    
    translate ([55,40,-25]) cylinder(50,d=7,true,$fn=100);
    translate ([18,63,-25]) cylinder(50,d=4.2,true,$fn=100);
    translate ([18,146,-25]) cylinder(50,d=4.2,true,$fn=100);
    translate ([92,63,-25]) cylinder(50,d=4.2,true,$fn=100);
    translate ([92,146,-25]) cylinder(50,d=4.2,true,$fn=100);
    translate ([55,104.5,0]) cube([62.6,68.4,50],true);
}
