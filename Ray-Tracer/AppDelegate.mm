//
//  AppDelegate.m
//  Ray Tracer
//
//  Created by Nick Maraston on 12-07-23.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"

#include "Scene.h"
#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include "Vector.h"
#include "Renderer.h"


/*
 * AppDelegate class implementation.
 */
@implementation AppDelegate

@synthesize window = _window;

- (void)dealloc
{
    [super dealloc];
}

/*
 * Ray Tracing demo.
 */
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    Vector3d sphere1_center(-20, 0, -60);
	Sphere sphere1(sphere1_center, 18);
    
    Vector3d sphere2_center(20, 0, -60);
    Sphere sphere2(sphere2_center, 18);
    
	// Create lights.
	Vector3d light1_origin(-40, 35, 0);
	Light light1(light1_origin, 1);
    
	// Set up the scene with a single sphere sitting in the negative region of 
    // the z-axis.
	Scene scene;
    scene.add_surface(&sphere1);
	scene.add_surface(&sphere2);
	scene.add_light(&light1);
    
	// Set up camera on the z-axis directed towards the negative region of the 
    // z-axis with a focal distance of 5.
	Vector3d cam_origin(0, 0, 0);
	Vector3d cam_direction(0, 0, -1);
	Vector3d up(0, 1, 0);
	Camera cam(cam_origin, cam_direction, up, 50);
    
	// Image speifications.
	ImagePlane imgpl(100, 100, 500, 500);
    
	// Set up the renderer.
	Renderer renderer(&scene, &cam, &imgpl);
    
	// Say cheese.
	renderer.render();
}

@end
