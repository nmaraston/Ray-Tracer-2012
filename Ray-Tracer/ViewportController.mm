//
//  ViewportController.m
//  Ray-Tracer
//
//  Created by Nick Maraston on 12-07-28.
//
//

#import "ViewportController.h"

@implementation ViewportController


@synthesize viewport;
@synthesize cameraControl;


/*
 *
 */
- (IBAction)adjustCamera:(id)sender
{
    if ([sender isKindOfClass:[Viewport class]]) {
        NSLog(@"%i", [viewport getDeltaX]);
    }
}


/*
 *
 */
- (IBAction)changeCameraControl:(id)sender
{
    if ([sender isKindOfClass:[NSSegmentedControl class]]) {
        NSLog(@"%li", [cameraControl selectedSegment]);
    }
}


@end
