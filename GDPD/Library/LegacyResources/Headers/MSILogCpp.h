//
//  MSILog.h
//  ReportServiceCore
//
//  Created by Sun on 6/15/18.
//  Copyright © 2018 MicroStrategy, Inc. All rights reserved.
//

#ifndef MSILogCpp_h
#define MSILogCpp_h

class MSILogCpp {
public:
    static void addLog(const char* message, const char* className, const char* method);
    static std::string DSSErrorLogPath();
    static void resetDSSErrorLog();
};

#endif /* MSILog_h */
