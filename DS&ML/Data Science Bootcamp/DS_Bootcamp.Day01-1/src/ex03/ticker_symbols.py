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

def ticker_symbols(ticker):
    COMPANIES, STOCKS = companis()
    res = None
    
    for key, value in COMPANIES.items():
        if value == ticker:
            res = key

    if (res):
        print(res,  STOCKS.get(ticker))
    else:
        print("Unknown ticker")


if __name__ == '__main__':

    if len(sys.argv) == 2:
        ticker_symbols(sys.argv[1].upper())