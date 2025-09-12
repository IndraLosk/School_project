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
        return STOCKS.get(ticker)

def ticker_symbols(ticker):
    COMPANIES, STOCKS = companis()
    res = None
    
    for key, value in COMPANIES.items():
        if value == ticker:
            res = key

    if (res):
        return res

def all_stocks(stocks):
    for stock in stocks:
        stock = stock.strip()
        sp = None
        if(sp := stock_prices(stock.capitalize())):
            print(stock.capitalize(), "stock price is", sp)
        elif (sp := ticker_symbols(stock.upper())):
            print(stock.upper(), "is a ticker symbol for", sp)
        else:
            print(stock, "is an unknown company or an unknown ticker symbol")

if __name__ == '__main__':
    if (len(sys.argv) == 2):
        stocks = sys.argv[1].split(",")
        if(all(stock.strip() for stock in stocks)):
            all_stocks(stocks)