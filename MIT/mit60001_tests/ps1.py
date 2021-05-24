import pytest
from mit60001 import ps1a, ps1b, ps1c


@pytest.mark.parametrize(
    "annual_salary, portion_saved, total_cost, expected_result",
    [(120000, 0.10, 1000000, 183), (80000, 0.15, 500000, 105)],
)
def test_problem_set_1a(annual_salary, portion_saved, total_cost, expected_result):
    output = ps1a.number_of_months_to_save(annual_salary, portion_saved, total_cost)
    assert output == expected_result


@pytest.mark.parametrize(
    "annual_salary, portion_saved, total_cost, semi_annual_raise, expected_result",
    [
        (120000, 0.05, 500000, 0.03, 142),
        (80000, 0.1, 800000, 0.03, 159),
        (75000, 0.05, 1500000, 0.05, 261),
    ],
)
def test_problem_set_1b(
    annual_salary, portion_saved, total_cost, semi_annual_raise, expected_result
):
    output = ps1b.number_of_months_to_save(
        annual_salary, portion_saved, total_cost, semi_annual_raise
    )
    assert output == expected_result


@pytest.mark.parametrize(
    "starting_salary, savings_rate, bisection_steps",
    [
        (150000, 0.4411, 12),
        (300000, 0.2206, 13),
        (10000, 0.0, 0.0),
    ],
)
def test_problem_set_1c(starting_salary, savings_rate, bisection_steps):
    output_savings, output_bisection_step = ps1c.bisection_search(starting_salary)
    assert output_bisection_step == bisection_steps
    assert abs(output_savings - savings_rate) <= 0.03
