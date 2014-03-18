#!/usr/bin/python


months=[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
weekdays=['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']
WEEK=7
empty=0 #1900 nian 0

def GetEmpty(year):
    temp = GetFebruary(year)
    if (temp == 29):
        days=366
    else:
        days=365
    empty=days%7
    return empty

def GetFebruary(year):
    if (year % 100 == 0):
        if (year % 400):
            Feb = 29
        else:
            Feb = 28
    elif ( year % 4 == 0 ):
        Feb = 29
    else:
        Feb = 28
    return Feb

def GenCalendar(year):
    print year

    first = empty
    months[1] = GetFebruary(year)
    if (year < 1900):
        for i in range(year, 1900):
            first -= GetEmpty(year)
    else:
        for i in range(1901, year+1):
            first += GetEmpty(year)
    first %= 7
    weekday = first
    for i in range(12): #0...11
        print 
        for week in range(WEEK):
            print "%s\t" %(weekdays[week]),
        print
        for j in range(1, months[i]+1): #0...months[i]-1
            for k in range(first):
                print "\t",
            print "%d\t" %(j),
            weekday += 1
            if (weekday%7 == 0):
                print 
                weekday = 0
            first = weekday

if __name__=='__main__':
#    print "Calendar 2012"
#    GenCalendar(2012)
#    print "Calendar 2013"
#    GenCalendar(2013)
    print "Calendar 1900"
    GenCalendar(1900)
