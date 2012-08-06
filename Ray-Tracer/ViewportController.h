//
//  ViewportController.h
//  Ray-Tracer
//
//  Created by Nick Maraston on 12-07-28.
//
//

#import <Foundation/Foundation.h>
#import "Viewport.h"

@interface ViewportController : NSResponder

@property (assign) IBOutlet Viewport *viewport;
@property (assign) IBOutlet NSSegmentedControl *cameraControl;

- (IBAction) adjustCamera:(id)sender;
- (IBAction) changeCameraControl:(id)sender;

@end
