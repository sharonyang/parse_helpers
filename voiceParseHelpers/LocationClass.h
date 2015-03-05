//
//  LocationClass.h
//  voiceParseHelpers
//
//  Created by Sharon Yang on 3/5/15.
//  Copyright (c) 2015 Sharon Yang. All rights reserved.
//

#ifndef voiceParseHelpers_LocationClass_h
#define voiceParseHelpers_LocationClass_h

//#import <Parse/Parse.h>

@interface LocationClass:NSObject

/* method declaration */
//- (void)updateLocation:(PFGeoPoint **)geoPoint :(NSDATE **)date;
//- (NSArray *)findNearestUsers:(PFGeoPoint *)userGeoPoint :(int)numUsers;

@end

@implementation LocationClass

/* updateLocation
 *   input: a pointer to location, a pointer to date object
 *   output: nothing, but the input pointers are modified
 *
 *   note: if parse encounters an error, we do not update the
 *   current location or time
 */
/*
 - (void)updateLocation:(PFGeoPoint **)geoPoint :(NSDATE **)date {
 // Get current location as a GeoPoint
 [PFGeoPoint geoPointForCurrentLocationInBackground:^(PFGeoPoint *currGeoPoint, NSError *error) {
 if (!error) {
 *geoPoint = currGeoPoint;
 }
 else {
 // If we did not get a location, we leave the function without modifying
 // both the GeoPoint and the date object.
 return;
 }
 }];
 
 *date = [NSDate date];
 }
 */

/* findNearestUsers
 *   input: a GeoPoint for user's current location, an int specifying
 *          desired number of nearest users
 *   output: an array of nearest User objects
 *
 */
/*
 - (NSArray *)findNearestUsers:(PFGeoPoint *)userGeoPoint :(int)numUsers {
 // Create a query for places
 PFQuery *query = [PFQuery queryWithClassName:@"User"];
 // Interested in locations near user
 [query whereKey:@"lastLocation" nearGeoPoint:userGeoPoint];
 // Limit on number of users
 query.limit = numUsers;
 // Final list of objects
 NSArray *nearestUsers = [query findObjects];
 
 return nearestUsers;
 }
 */

@end

#endif
