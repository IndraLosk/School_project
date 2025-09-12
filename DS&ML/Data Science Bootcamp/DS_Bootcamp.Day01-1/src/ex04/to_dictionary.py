def convert_to_dict():
    list_of_tuples = [
        ('Russia', '25'),
        ('France', '132'),
        ('Germany', '132'),
        ('Spain', '178'),
        ('Italy', '162'),
        ('Portugal', '17'),
        ('Finland', '3'),
        ('Hungary', '2'),
        ('The Netherlands', '28'),
        ('The USA', '610'),
        ('The United Kingdom', '95'),
        ('China', '83'),
        ('Iran', '76'),
        ('Turkey', '65'),
        ('Belgium', '34'),
        ('Canada', '28'),
        ('Switzerland', '26'),
        ('Brazil', '25'),
        ('Austria', '14'),
        ('Israel', '12')
    ]

    country_dict = {}

    for country, number in list_of_tuples:
        if number not in country_dict:
            country_dict[number] = [country]
        else:
            country_dict[number].append(country)

    for number, countries in country_dict.items():
        for country in countries:
            print(f"'{number}': '{country}'")


if __name__ == '__main__':
    convert_to_dict()