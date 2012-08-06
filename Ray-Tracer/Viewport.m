//
//  Viewport.m
//  Ray-Tracer
//
//  Created by Nick Maraston on 12-07-28.
//
//

#import "Viewport.h"

@implementation Viewport


/*
 * Always accept first responder status.
 */
- (BOOL) acceptsFirstResponder
{
    return YES;
}

- (void) awakeFromNib
{
    deltaX = 0;
    deltaY = 0;
}


/*
 * Record the change in mouse position and notify the target.
 */
- (void) mouseDragged:(NSEvent*)event
{
    deltaX = [event deltaX];
    deltaY = [event deltaY];
    [self sendAction:action to:target];
}


/*
 * Return the change in mouse position, with respect to the x-axis, that 
 * occured on the last mouse dragged event.
 */
- (int) getDeltaX
{
    return deltaX;
}


/*
 * Return the change in mouse position, with respect to the y-axis, that
 * occured on the last mouse dragged event.
 */
- (int) getDeltaY
{
    return deltaY;
}


/*
 * Accessors to support direct storage of action and target without using a 
 * NSCell.
 */
- (SEL) action { return action; }
- (void) setAction:(SEL)aSelector { action = aSelector; }
- (id) target { return target; }
- (void) setTarget:(id)anObject { target = anObject; }


@end
