//
//  InsertionClass.h
//  voiceParseHelpers
//
//  Created by Sharon Yang on 3/5/15.
//  Copyright (c) 2015 Sharon Yang. All rights reserved.
//

#ifndef voiceParseHelpers_InsertionClass_h
#define voiceParseHelpers_InsertionClass_h

//#import <Parse/Parse.h>

@interface InsertionClass:NSObject

/* method declaration */
- (BOOL)validPhone:(NSString *)phoneNumber :(NSString **)cleanedString;

@end

@implementation InsertionClass

/* validPhone
 *   input: an input phone number string, a pointer to store result string
 *   output: a boolean value stating whether the phone number is valid
 *
 *   note:
 *   this function can be used to check both personal phone number and university's
 *   if output is valid, cleanedString is the modified string of phone number
 *   to be saved. if output is not valid, cleanedString is the error message.
 *
 */
- (BOOL)validPhone:(NSString *)phoneNumber :(NSString **)cleanedString {
    // Strip input string of non-numeric characters.
    *cleanedString = [[phoneNumber componentsSeparatedByCharactersInSet:[[NSCharacterSet characterSetWithCharactersInString:@"0123456789"] invertedSet]] componentsJoinedByString:@""];

    // Format phone number string into (xxx)xxx-xxxx
    NSMutableString *stringts = [NSMutableString stringWithString:*cleanedString];
    [stringts insertString:@"(" atIndex:0];
    [stringts insertString:@")" atIndex:4];
    [stringts insertString:@"-" atIndex:8];
    *cleanedString = stringts;

    // Check if the result is a valid phone number
    // NOTE: US PHONE NUMBER ONLY!
    NSUInteger len = [*cleanedString length];
    if (len != 13) {
        *cleanedString = @"The phone number must be a valid US phone number.";
        return false;
    }

    // Check if the phone number already exists in the database - User class
    /*
     PFQuery *query = [PFQuery queryWithClassName:@"User"];
     [query whereKey:@"phoneNumber" equalTo:*cleanedString];
     [query countObjectsInBackgroundWithBlock:^(int count, NSError *error) {
     if (!error) {
     if (count > 0) {
     *cleanedString = @"This phone number is already used by some other user.";
     return false;
     }
     } else {
     *cleanedString = @"Could not connect to database.";
     return false;
     }
     }];
     
     // Check if the phone number already exists in the database - University class
     PFQuery *query2 = [PFQuery queryWithClassName:@"University"];
     [query2 whereKey:@"securityNumber" equalTo:*cleanedString];
     [query2 countObjectsInBackgroundWithBlock:^(int count, NSError *error) {
     if (!error) {
     if (count > 0) {
     *cleanedString = @"This security phone number has already been used.";
     return false;
     }
     } else {
     *cleanedString = @"Could not connect to database.";
     return false;
     }
     }];
     
     */
    
    return true;
}

@end

#endif
