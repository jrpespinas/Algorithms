"""
MIT 6.0001 - Introduction to Computer Science and Programming in Python
Problem Set 1 - A
-------------

You have graduated from MIT and now have a great job! You move to the San Francisco Bay Area and decide
that you want to start saving to buy a house. As housing prices are very high in the Bay Area, you realize
you are going to have to save for several years before you can afford to make the down payment on a house.

In part A, we are going to determine how long it will take you to save enough money to make the down payment 
given the following assumptions:

    1. Call the cost of your dream home `total_cost`.
    2. Call the portion of the cost needed for a down payment `portion_down_payment`. For simplicity,
        assume that `portion_down_payment` = 0.25 (25%).
    3. Call the amount that you have saved thus far `current_savings`. You start with a currewnt savings of $0.
    4. Assume that you invest your current savings wisely, with an annual return of `r` (in other words, at the
        end of each month, you receive an additional `current_savings * r / 12` funds to put into your savings - 
        the 12 is because `r` is an annual rate). Assume that your investments earn a return of r = 0.04 (4%).
    5. Assume your annual salary is `annual_salary`.
    6. Assume you are going to dedicate a certain amount of your salary each month to saving for the down payment.
        Call that `portion_saved`. This variable should be in decimal form (i.e 0.1 for 10%).
    7. At the end of each month, your savings will be increase by the return on your investment, plus a percentage
        oof your `monthly salary` (annual salary / 12).

Write a program to calculate how many months it will take you to save up enough money for a down payment. You will
want your main variables to be floats, so you should cast user inputs to floats.

Your program should ask the user to enter the following variables:
    1. The starting annual salary `annual_salary`.
    2. The portion of salary to be saved `portion_saved`.
    3. The cost of your dream home `total_cost`.

Test Case 1
===========
>>> Enter your annual salary: 120000
>>> Enter the percent of your salary to save, as a decimal: .10
>>> Enter the cost of your dream home: 1000000
>>> Number of months: 183

Test Case 2
===========
>>> Enter your annual salary: 80000
>>> Enter the percent of your salary to save, as a decimal: .15
>>> Enter the cost of your dream home: 500000
>>> Number of months: 105
"""

PORTION_DOWN_PAYMENT = 0.25


def number_of_months_to_save(
    annual_salary: float, portion_saved: float, total_cost: float
):
    pass


def get_down_payment(total_cost: float) -> float:
    return total_cost * PORTION_DOWN_PAYMENT


def get_monthly_salary(annual_salary: float) -> float:
    return annual_salary / 12


def main():
    annual_salary = float(input("Enter your annual salary: "))
    portion_saved = float(
        input("Enter the percent oif your salary to save, as a decimal: ")
    )
    total_cost = float(input("Enter the cost of your dream home: "))
    number_of_months = number_of_months_to_save(
        annual_salary, portion_saved, total_cost
    )

    print("Number of months:", number_of_months)


if __name__ == "__main__":
    main()
