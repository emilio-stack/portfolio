# 1. Name:
#      Emilio Regino
# 2. Assignment Name:
#      Lab 03 : Calendar Program
# 3. Assignment Description:
#      This program displays a calendar for any month of any year after 1752.
# 4. What was the hardest part? Be as specific as possible.
#      This assignment wasn't too much trouble for me as designing a structure chart
#      really sped up the process compared to last week's tic tac toe program. I felt
#      good about my solution and I incorporated the design table function into it this week.
#
#      I would say that the hardest part was ordering the if statements in functions like
#      is_leap or days_in_month. While it was the hardest part it was also the part of the
#      program that was most fun for me as I tried to make a decision in as little if
#      statements as possible.
# 5. How long did it take for you to complete the assignment?
#      4 Hours


def get_month():
    """This function gets the month the user wants to display"""
    possible_months = {1, 2, 3, 4, 5, 6, 7,
                       8, 9, 10, 11, 12}

    # Prompt for the month's corresponding integer.
    month = input("Enter a month number: ")


    # Handle errors. 
    valid = False
    while not valid:
        valid =  True
        if not month.isdigit():
            print("Must must be an integer!")
            valid = False
            month = 1
        else:
            month = int(month)

        if month < 1 or month > 12:
            print("Month must be between 1 and 12!")
            valid = False
        
        if not valid:
            month = input("Enter a month number: ")

    # # Reprompt if user input cannot be parsed as type int.
    # while type(month) != int:
    #     try:
    #         month = int(month)
    #     except ValueError:
    #         print("\nNot a valid month number.")
    #         print("Enter the integer corresponding to the month (1-12)")
    #         month = input(">")

    # # Integer must be 1-12.
    # while month not in possible_months:

    #     # Check to make sure loop logic is correct.
    #     # This assert should only fire when month is invalid.
    #     assert month not in possible_months, "Month is valid"

    #     print("\nNot a valid month number.")
    #     print("Enter the integer corresponding to the month (1-12)")
    #     month = int(input(">"))

    return month


def get_year():
    """This function gets the year the user wants to display"""
    # Prompt for the year.
    year = input("Enter a year: ")

    # Reprompt if user input cannot be parsed as type int.
    while type(year) != int:
        try:
            year = int(year)
        except ValueError:
            print("\nNot a valid year.")
            print("Enter a year greater than 1753.")
            year = int(input(">"))

    # Year must be greater than 1752.
    while year < 1753:

        # Check to make sure loop logic is correct.
        # This assert should only fire when year is invalid.
        assert year <= 1752, "Year is valid"

        print("\nNot a valid year.")
        print("Enter a year greater than 1753.")
        year = int(input(">"))

    return year


def calc_offset(month, year):
    """This function calculates which day of the week the month starts on."""

    # Initialize the variable to 0.
    num_days_since_1753 = 0

    # We do not include the selected year.
    # This handles the case where only part of the year has passed.
    for each_year in range(1753, year, 1):
        num_days_since_1753 += days_in_year(each_year)
        assert each_year != year, "Selected year was included in the iteration."

    # We do not include the selected month.
    # We do not factor in the days of the selected month to calculate the offset.
    for each_month in range(1, month, 1):
        num_days_since_1753 += days_in_month(each_month, year)
        assert each_month != year, "Selected month was included in the iteration."

    # We will divide by 7 to see how many weeks have passed.
    # The remaining days will tell us day of the week that the month starts.
    offset = (num_days_since_1753 + 1) % 7

    return offset


def days_in_year(year):
    """This function calculates the days in a given year."""
    # Initialize the variable.
    num_days = 0

    # Check if the year is leap.
    # There are more non-leap years so we will make this the trivial case.
    if is_leap(year) == False:
        num_days = 365
        return num_days

    # This is the special case.
    else:
        num_days = 366
        return num_days


def days_in_month(month, year):
    """This function calculates the days in a given year."""
    # Only 4 possibilities for the number of days in a month.
    possible_month_days = [31, 30, 28, 29]

    # Initialize the variable.
    num_days = 0

    # If the month is odd, it has 31 days.
    if month % 2 != 0:
        num_days = possible_month_days[0]
        return num_days

    # The month must therefore be even.
    # If it is not month 2, then it has 30 days.
    elif month != 2:
        num_days = possible_month_days[1]
        return num_days

    # This is the special case of month 2.
    else:

        # If it is not a leap year, the month has 28 days.
        if is_leap(year) == False:
            num_days = possible_month_days[2]
            return num_days

        # If it is a leap year, the month has 29 days.
        else:
            num_days = possible_month_days[3]
            return num_days


def is_leap(year):
    """This function decides if a given year is a leap year."""
    # If the year is not divisible by 4, it is not a leap year.
    if year % 4 != 0:
        return False

    # If the year is divisible by 4 but not 100, it is a leap year.
    if year % 100 != 0:
        return True

    # If the year is divisible by 4 and 100 but not 400, it is not a leap year.
    if year % 400 != 0:
        return False

    # Else the year is leap.
    return True


def display_calendar(month, year):
    """This function displays the calendar."""
    # Get the day of the week for the 1st of the month.
    #    dow = day of month.
    dow = calc_offset(month, year)
    num_days = days_in_month(month, year)
    display_table(dow, num_days)


def display_table(dow, num_days):
    '''Display a calendar table'''
    assert(type(num_days) == type(dow) == type(0))
    assert(0 <= dow <= 6)
    assert(28 <= num_days <= 31)

    # Display a nice table header
    print("  Su  Mo  Tu  We  Th  Fr  Sa")

    # Indent for the first day of the week
    for indent in range(dow):
        print("    ", end='')

    # Display the days of the month
    for dom in range(1, num_days + 1):
        print(repr(dom).rjust(4), end='')
        dow += 1
        # Newline after Saturdays
        if dow % 7 == 0:
            print("")  # newline

    # We must end with a newline
    if dow % 7 != 0:
        print("")  # newline


# Test
while True:
    # Prompt the user for month and year.
    month = get_month()
    year = get_year()

    # Display the calendar.
    display_calendar(month, year)
