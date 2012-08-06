//
//  Viewport.h
//  Ray-Tracer
//
//  Created by Nick Maraston on 12-07-28.
//
//

/*
 * A Viewport serves two purposes. Primarily, it provides an NSView for OpenGL
 * rendering. Additionaly, it serves as a NSControl that records changes in 
 * mouse positions when a mouseDragged event occurs on the Viewport. These
 * changes can be read by the Viewport's target through access functions: deltaX
 * and deltaY.
 */
@interface Viewport : NSControl
{
    @private
        
        int deltaX;
        int deltaY;
    
        // NSCells are not used here. Action and target must be stored locally.
        SEL action;
        id target;
}

/*
 * Getters for change in mouse position. Both functions return the change in
 * mouse position, with respect to the X or Y axis, that occured on the last 
 * mouse dragged event.
 */
- (int) getDeltaX;
- (int) getDeltaY;


/*
 * Overriding action/target accessors to support storage of action and target 
 * directly in the Viewport object rather then a contained NSCell.
 */
- (SEL) action;
- (void) setAction:(SEL)aSelector;
- (id) target;
- (void) setTarget:(id)anObject;

@end
