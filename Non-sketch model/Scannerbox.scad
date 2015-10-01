include <MCAD/units.scad>

side_len = 1.2*inch;
wall_thickness = 2*mm;
hole_d = 1.95*cm;

module lowerPrint() {
        difference(){
            cube(side_len, center=true);
            cube(side_len - 2*wall_thickness, center=true);
            rotate([90,0,0])
            cylinder(h = 2*side_len, d = hole_d, center= true, $fn = 100);
            translate([0,0,side_len - wall_thickness - 0.001]) 
                cube(side_len+0.001, center=true);
        }
}

module wireHole() {
    cylinder(d=2*mm, h =9999, center=true, $fn = 30);
}

module upperPrint() {
    difference(){
        union(){
            cube([side_len, side_len, wall_thickness], center=true);
            translate([0,0,wall_thickness * 0.25])  cube([side_len - 2*wall_thickness, side_len - 2*wall_thickness, 1.5*wall_thickness], center=true);
        }
        
        translate([0,0,wall_thickness]) cube([side_len - 4*wall_thickness, side_len - 4*wall_thickness, .999*wall_thickness], center=true);
        
        translate([5*mm,2*mm,0]) wireHole();
        translate([5*mm,-2*mm,0]) wireHole();
        translate([-5*mm,2*mm,0]) wireHole();
        translate([-5*mm,-2*mm,0]) wireHole();
        
    }
}

translate([side_len*1.5, 0]) upperPrint();
lowerPrint();