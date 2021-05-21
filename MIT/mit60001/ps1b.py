"""
MIT 6.0001 - Introduction to Computer Science and Programming in Python
Problem Set 1 - B
-------------

In Part A, we unrealistically assumed that your salary didn’t change.  But you are an MIT graduate, and
clearly you are going to be worth more to your company over time! So we are going to build on your
solution to Part A by factoring in a raise every six months.

In ps1b.py​, copy your solution to Part A (as we are going to reuse much of that machinery).  Modify
your program to include the following:
    1. Have the user input a semi-annual salary raise `semi_annual_raise`​ (as a decimal percentage)
    2. After the 6th month, increase your salary by that percentage.  Do the same after the 12th
        month, the 18th  month, and so on. 

Write a program to calculate how many months it will take you save up enough money for a down
payment.  LIke before, assume that your investments earn a return of r​ = 0.04 (or 4%) and the
required down payment percentage is 0.25 (or 25%).  Have the user enter the following variables:

Your program should ask the user to enter the following variables:
    1. The starting annual salary `annual_salary`.
    2. The portion of salary to be saved `portion_saved`.
    3. The cost of your dream home `total_cost`.
    4. The semi-annual salary raise `semi_annual_raise`.

Test Case 1
===========
>>> Enter your annual salary: 120000
>>> Enter the percent of your salary to save, as a decimal: .05
>>> Enter the cost of your dream home: 500000
>>> Enter the semi-annual raise, as a decimal: .03
>>> Number of months: 142

Test Case 2
===========
>>> Enter your annual salary: 80000
>>> Enter the percent of your salary to save, as a decimal: .1
>>> Enter the cost of your dream home: 800000
>>> Enter the semi-annual raise, as a decimal: .03
>>> Number of months: 159

Test Case 3
===========
>>> Enter your annual salary: 75000
>>> Enter the percent of your salary to save, as a decimal: .05
>>> Enter the cost of your dream home: 1500000
>>> Enter the semi-annual raise, as a decimal: .05
>>> Number of months: 261
"""


PORTION_DOWN_PAYMENT = 0.25
ANNUAL_SAVINGS_RATE = 0.04


def number_of_months_to_save(
    annual_salary: float,
    portion_saved: float,
    total_cost: float,
    semi_annual_raise: float,
) -> int:

    current_savings = 0
    portion_down_payment = get_portion_down_payment(total_cost)
    monthly_salary = get_monthly_salary(annual_salary)

    months = 0
    while current_savings <= portion_down_payment:
        current_savings = (
            current_savings
            + get_savings_portion(monthly_salary, portion_saved)
            + get_investments_return(current_savings)
        )

        months += 1

        if months % 6 == 0:
            monthly_salary = get_salary_raise(monthly_salary, semi_annual_raise)

    return months


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
    annual_salary = float(input("Enter your annual salary: "))
    portion_saved = float(
        input("Enter the percent of your salary to save, as a decimal: ")
    )
    total_cost = float(input("Enter the cost of your dream house: "))
    semi_annual_raise = float(input("Enter the semi-annual raise, as a decimal: "))
    months = number_of_months_to_save(
        annual_salary, portion_saved, total_cost, semi_annual_raise
    )

    print("Number of months", months)


if __name__ == "__main__":
    main()
