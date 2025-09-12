import sys

def companis():
    COMPANIES = {
        'Apple': 'AAPL',
        'Microsoft': 'MSFT',
        'Netflix': 'NFLX',
        'Tesla': 'TSLA',
        'Nokia': 'NOK'
    }

    STOCKS = {
        'AAPL': 287.73,
        'MSFT': 173.79,
        'NFLX': 416.90,
        'TSLA': 724.88,
        'NOK': 3.37
    }

    return COMPANIES, STOCKS

def stock_prices(company_name):
    COMPANIES, STOCKS = companis()
    ticker = COMPANIES.get(company_name)
    if(ticker):
        print(STOCKS.get(ticker))
    else:
        print("Unknown company")

if __name__ == '__main__':

    if len(sys.argv) == 2:
        stock_prices(sys.argv[1].capitalize())