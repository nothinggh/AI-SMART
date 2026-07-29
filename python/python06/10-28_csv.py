import csv

min_temp = None
min_date =''

with open('/mnt/c/Temp/weather.csv','r') as infile:
    reader = csv.DictReader(infile)

    for row in reader:
        temp =float(row['최저기온(℃)'])

        if min_temp is None or temp < min_temp:
            min_temp=temp
            min_date=row['날짜']

print(f'최저기온(℃):{min_temp}')
print(f'날짜:{min_date}')
