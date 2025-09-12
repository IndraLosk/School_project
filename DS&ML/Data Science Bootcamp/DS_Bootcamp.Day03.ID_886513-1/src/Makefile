all: ex00 ex01 ex02 ex03 ex05

ex00:
	@echo '' 
	@echo "0 Задание"
	@echo '' 
	@python3 ex00/venv.py
	@echo '' 

ex01:
	@echo '' 
	@echo "1 Задание"
	@echo '' 
	@sh ex01/pies_bars.sh
	@echo ''

ex02:
	@echo '' 
	@echo "2 Задание"
	@echo '' 
	@python3 ex02/librarian.py
	@tar -czvf ex02/nilahugh.tar.gz ex00/nilahugh/
	@echo ''

ex03:
	@echo '' 
	@echo "3 Задание"
	@echo '' 
	@python3 ex03/financial.py 'MSFT' 'Total Revenue'
	@echo ''

ex05:
	@echo '' 
	@echo "5 Задание"
	@echo '' 
	@pytest ex05/financial_test.py
	@echo ''
	rm -r ex05/__pycache__
	rm -r ex05/.pytest_cache


style:
	black ex00/*.py 
	black ex02/*.py 
	black ex03/*.py 
	black ex04/*.py 
	black ex05/*.py 

.PHONY: all ex00 ex01 ex02 ex03 ex05 style

clean_ex02:
	rm -f ex02/requirements.txt
	pip uninstall beautifulsoup4
	pip uninstall pytest
	rm ex02/nilahugh.tar.gz