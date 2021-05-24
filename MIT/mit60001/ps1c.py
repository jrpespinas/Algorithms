"""
MIT 6.0001 - Introduction to Computer Science and Programming in Python
Problem Set 1 - C
-------------

In Part B, you had a chance to explore how both the percentage of your salary that you save each month 
and your annual raise affect how long it takes you to save for a down payment.  This is nice, but
suppose you want to set a particular goal, e.g. to be able to afford the down payment in three years.
How much should you save each month to achieve this?  In this problem, you are going to write a 
program to answer that question. To simplify things, assume:

    1. Your semi­annual raise is .07 (7%)
    2. Your investments have an annual return of 0.04 (4%)  
    3. The down payment is 0.25 (25%) of the cost of the house 
    4. The cost of the house that you are saving for is $1M

You are now going to try to find the best rate of savings to achieve a down payment on a $1M house in 
36 months. Since hitting this exactly is a challenge, we simply want your savings to be within $100 of 
the required down payment.

In ps1c.py​, write a program to calculate the best savings rate, as a function of your starting salary.
You should use bisection search​ to help you do this efficiently. You should keep track of the number of 
steps it takes your bisections search to finish. You should be able to reuse some of the code you wrote
for part B in this problem.  

Because we are searching for a value that is in principle a float, we are going to limit ourselves to two
decimals of accuracy (i.e., we may want to save at 7.04% ­­ or 0.0704 in decimal – but we are not 
going to worry about the difference between 7.041% and 7.039%).  This means we can search for an
integer​ between 0 and 10000 (using integer division), and then convert it to a decimal percentage
(using float division) to use when we are calculating the current_savings​ after 36 months. By using
this range, there are only a finite number of numbers that we are searching over, as opposed to the
infinite number of decimals between 0 and 1. This range will help prevent infinite loops. The reason we
use 0 to 10000 is to account for two additional decimal places in the range 0% to 100%. Your code
should print out a decimal (e.g. 0.0704 for 7.04%).

Try different inputs for your starting salary, and see how the percentage you need to save changes to
reach your desired down payment.  Also keep in mind it may not be possible for to save a down
payment in a year and a half for some salaries. In this case your function should notify the user that it 
is not possible to save for the down payment in 36 months with a print statement. Please make your
program print results in the format shown in the test cases below.

Note: There are multiple right ways to implement bisection search/number of steps so your
results may not perfectly match those of the test case.

Test Case 1
===========
>>> Enter the starting salary: 150000
>>> Best savings rate: 0.4411
>>> Steps in bisection search: 12 

Test Case 2
===========
>>> Enter the starting salary: 300000
>>> Best savings rate: 0.2206
>>> Steps in bisection search: 9

Test Case 3
===========
>>> Enter the starting salary: 10000
>>> It is not possible to pay the down payment in three years
"""
SEMI_ANNUAL_RAISE = 0.07
PORTION_DOWN_PAYMENT = 0.25
TOTAL_COST = 1e6
TARGET_MONTH = 36
ANNUAL_SAVINGS_RATE = 0.04


def bisection_search(annual_salary: float) -> float:

    left = 0
    right = 1
    savings_rate = right
    portion_down_payment = get_portion_down_payment(TOTAL_COST)
    current_savings = savings(annual_salary, savings_rate)

    bisection_step = 0
    temp = 0
    while abs(portion_down_payment - current_savings) >= 100:
        if portion_down_payment > current_savings:
            left = savings_rate
        else:
            right = savings_rate

        bisection_step += 1

        savings_rate = (left + right) / 2
        current_savings = savings(annual_salary, savings_rate)

        if savings_rate == temp:
            print("It is not possible to pay the down payment in three years.")
            return 0.0, 0.0

        temp = savings_rate
        print(savings_rate)

    return savings_rate, bisection_step


def savings(annual_salary: float, portion_saved: float) -> int:

    current_savings = 0
    portion_down_payment = get_portion_down_payment(TOTAL_COST)
    monthly_salary = get_monthly_salary(annual_salary)

    for months in range(0, TARGET_MONTH):
        current_savings = (
            current_savings
            + get_savings_portion(monthly_salary, portion_saved)
            + get_investments_return(current_savings)
        )

        if months % 6 == 0:
            monthly_salary = get_salary_raise(monthly_salary, SEMI_ANNUAL_RAISE)

    return current_savings


def get_salary_raise(monthly_salary: float, semi_annual_raise: float) -> float:
    return monthly_salary + (monthly_salary * semi_annual_raise)


def get_savings_portion(monthly_salary: float, portion_saved: float) -> float:
    return monthly_salary * portion_saved


def get_portion_down_payment(total_cost: float) -> float:
    return total_cost * PORTION_DOWN_PAYMENT


def get_monthly_salary(annual_salary: float) -> float:
    return annual_salary / 12


def get_investments_return(current_savings: float) -> float:
    return current_savings * ANNUAL_SAVINGS_RATE / 12


def main():
    starting_salary = float(input("Enter the starting salary: "))
    savings_rate, bisection_step = bisection_search(starting_salary)
    print(
        f"Savings: {savings(starting_salary, savings_rate)}, bisection steps: {bisection_step}"
    )


if __name__ == "__main__":
    main()
