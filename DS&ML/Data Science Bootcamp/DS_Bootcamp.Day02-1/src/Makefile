# Цель по умолчанию
.DEFAULT_GOAL := all

.PHONY: all set_executable ex00 ex01 ex02 ex03 ex04 ex05 ex06

all: ex00 ex01 ex02 ex03 ex04 ex05 ex06

set_executable:
	chmod +x ex00/first_class.py
	chmod +x ex01/first_method.py
	chmod +x ex02/first_constructor.py
	chmod +x ex03/first_nest.py
	chmod +x ex04/first_child.py
	chmod +x ex05/config.py
	chmod +x ex05/analytics.py
	chmod +x ex05/make_report.py
	chmod +x ex06/config.py
	chmod +x ex06/analytics.py
	chmod +x ex06/make_report.py


ex00:
	@echo '' 
	@echo "0 Задание"
	@echo '' 
	@python3 ex00/first_class.py
ex01:
	@echo '' 
	@echo "1 Задание"
	@echo '' 
	@python3 ex01/first_method.py
ex02:
	@echo '' 
	@echo "2 Задание"
	@echo '' 
	@python3 ex02/first_constructor.py data.csv
ex03:
	@echo '' 
	@echo "3 Задание"
	@echo '' 
	@python3 ex03/first_nest.py data.csv
ex04:
	@echo '' 
	@echo "4 Задание"
	@echo '' 
	@python3 ex04/first_child.py data.csv
ex05: 
	@echo '' 
	@echo "5 Задание"
	@echo '' 
	@python3 ex05/make_report.py data.csv
ex06:
	@echo '' 
	@echo "6 Задание"
	@echo '' 
	@python3 ex06/make_report.py data.csv

style:
	black ex00/*.py
	black ex01/*.py
	black ex02/*.py
	black ex03/*.py
	black ex04/*.py
	black ex05/*.py
	black ex06/*.py

clean:
	rm -f report.txt
	rm -f analytics.log
	rm -r ex05/__pycache__
	rm -r ex06/__pycache__
