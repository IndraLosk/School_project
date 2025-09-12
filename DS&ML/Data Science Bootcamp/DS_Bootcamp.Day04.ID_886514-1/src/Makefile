all: ex00 ex01 ex02 ex03 ex04 ex05

ex00:
	@echo '' 
	@echo "0 Задание"
	@echo '' 
	@python3 ex00/benchmark.py
	@echo '' 

ex01:
	@echo '' 
	@echo "1 Задание"
	@echo '' 
	@python3 ex01/benchmark.py
	@echo ''

ex02:
	@echo '' 
	@echo "2 Задание"
	@echo '' 
	@chmod +x ex02/benchmark.py
	@./ex02/benchmark.py loop 10000000
	@./ex02/benchmark.py list_comprehension 10000000
	@./ex02/benchmark.py map 10000000
	@./ex02/benchmark.py
	@echo ''

ex03:
	@echo '' 
	@echo "3 Задание"
	@echo '' 
	@chmod +x ex03/benchmark.py
	@./ex03/benchmark.py loop 10000000 5
	@./ex03/benchmark.py reduce 10000000 5
	@echo ''

ex04:
	@echo '' 
	@echo "4 Задание"
	@echo '' 
	@chmod +x ex04/benchmark.py
	@./ex04/benchmark.py
	@echo ''

ex05:
	@echo '' 
	@echo "5 Задание"
	@echo '' 
	@chmod +x ex05/*.py
	@./ex05/ordinary.py ex05/ratings.csv
	@./ex05/generator.py ex05/ratings.csv
	@echo ''

style:
	black ex00/*.py 
	black ex01/*.py
	black ex02/*.py
	black ex03/*.py
	black ex04/*.py
	black ex05/*.py

.PHONY: all style ex00 ex01 ex02 ex03 ex04 ex05