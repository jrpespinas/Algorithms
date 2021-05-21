PORTION_DOWN_PAYMENT = 0.25
ANNUAL_SAVINGS_RATE = 0.04


def number_of_months_to_save(
    annual_salary: float, portion_saved: float, total_cost: float
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

    return months


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

    print(number_of_months_to_save(annual_salary, portion_saved, total_cost))


if __name__ == "__main__":
    main()
