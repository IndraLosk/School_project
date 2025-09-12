import financial
import pytest
import requests
import sys
import time
from bs4 import BeautifulSoup

# ('Total Revenue', '270,010,000', '245,122,000', '211,915,000', '198,270,000', '168,088,000')


def test_get_response_correct():
    ticker = "MSFT"
    html = financial.get_response(ticker)
    assert html


def test_get_response_incorrect():

    ticker = "Meow"
    with pytest.raises(Exception) as excinfo:
        financial.get_response(ticker)
    assert "Incorrect url" in str(excinfo.value)


def test_get_response_incorrect_number():

    ticker = 21
    with pytest.raises(Exception) as excinfo:
        financial.get_response(ticker)
    assert "Incorrect url" in str(excinfo.value)


def test_get_row_correct():
    soup = BeautifulSoup(financial.get_response("msft"), "html.parser")
    row = financial.get_row(soup, "Total Revenue")
    assert isinstance(row, tuple)
    assert row[0] == "Total Revenue"
    assert len(row) == 6


def test_get_row_correct_2():
    soup = BeautifulSoup(financial.get_response("msft"), "html.parser")
    row = financial.get_row(soup, "Tax Provision")
    assert isinstance(row, tuple)
    assert row[0] == "Tax Provision"
    assert len(row) == 6


def test_get_row_incorrect():
    with pytest.raises(Exception) as excinfo:
        soup = BeautifulSoup(financial.get_response("msft"), "html.parser")
        row = financial.get_row(soup, "Hmhm")
    assert "Incorrect field_name" in str(excinfo.value)


if __name__ == "__main__":
    test_get_response_correct()
    test_get_response_incorrect()
    test_get_response_incorrect_number()

    test_get_row_correct()
    test_get_row_correct_2()
    test_get_row_incorrect()
