#import "AppDelegate.h"

#include "Renderer.h"


/*
 * AppDelegate class implementation.
 */
@implementation AppDelegate

@synthesize window = _window;
@synthesize viewportController = _viewportController;

- (void)dealloc
{
    [super dealloc];
}

/*
 * 
 */
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    if ([_viewportController viewport] == nil) {
        NSLog(@"here");
    }
}
    
    

@end
