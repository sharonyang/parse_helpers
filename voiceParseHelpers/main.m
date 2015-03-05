//
//  Helper function to examine input before tuple insertions.
//  Parse integration is commented out.
//
//  Created by Sharon Yang on 3/5/15.
//  Copyright (c) 2015 Sharon Yang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InsertionClass.h"
#import "LocationClass.h"

int main(int argc, const char * argv[]) {

    InsertionClass *testInsertion = [[InsertionClass alloc] init];

    // Test validPhone
    NSString *phoneNumber = @"1233456789";
    NSString *cleanedString;
    BOOL result = [testInsertion validPhone:phoneNumber:&cleanedString];
    NSString *note = @"valid";
    if (!result)
        note = @"invalid";

    NSLog(@"%@ %@", cleanedString, note);

    LocationClass *testLocation = [[LocationClass alloc] init];
    //[testLocation test];

    return 0;
}
