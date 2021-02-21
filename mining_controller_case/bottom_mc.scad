difference (){
    union(){
        difference(){
            cube([120,170,40]);
            translate([5,5,5]) cube([110,160,100],false);
        }
        difference(){
            translate([5,5,5]) cube([110,160,33],false);
            translate([10,10,5]) cube([100,150,33],false);
        }    
    }
    translate([130,25,5]) rotate([0,0,90]) cube([20,100,15],false);
}