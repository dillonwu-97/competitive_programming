import time
import json
import pickle

from bs4 import BeautifulSoup

from selenium import webdriver
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.keys import Keys

import os

import requests

from collections import Counter

import argparse


def get_code(driver, redirect, name, language):
	print(redirect)
	driver.get('https://leetcode.com' + redirect)

	code = driver.find_element_by_class_name("ace_text-layer")
	# print(code.text)
	# print(name)
	# print(language)
	languages = {
		"python3": '.py',
		"cpp": '.cpp',
		"java": '.java',
		"c": 'c',
		"golang": '.go',
		"python": '.py',
		"mysql": '.sql',
		"bash": '.sh',
		"ruby": '.rb'
	}
	ext = languages.get(language, '.txt') # .txt is default 
	with open('./leetcode/' + name + ext, 'w') as f:
		f.write(code.text)

def main():

	# parser = argparse.ArgumentParser()
	# parser.add_argument("-u", "--username", help="Enter username", required=True)
	# parser.add_argument("-p", "--password", help="Enter password", required=True)
	# args = parser.parse_args()

	# create a folder for all leetcode problems
	if not os.path.exists("leetcode"):
		os.makedirs("leetcode")

	# create a json file that stores information about the problems that we've already seen when this script was run previously
	if not os.path.exists("visited.json"):
		with open('visited.json', 'w') as f:
			pass
		past_problems = {}
	else:
		if os.stat('visited.json').st_size != 0:
			with open('visited.json', 'r') as f:
				past_problems = json.load(f)
		else:
			past_problems = {}
	
	# store all solutions we have already seen 
	visited = {}

	login_url = 'https://leetcode.com/accounts/login/'

	# user = args.username
	# password = args.password

	# Use headless in order to reduce memory overhead when running Chrome
	# Note: headless makes the window not appear
	chrome_opts = webdriver.ChromeOptions()
	chrome_opts.add_argument("--headless")
	# chrome_opts.add_experimental_option("detach", True) # use this option to keep the window open

	# Go to the webpage
	driver = webdriver.Chrome('./chromedriver', options = chrome_opts)  # Optional argument, if not specified will search path.
	driver.get(login_url);

	# Log in to the site
	# driver.find_element_by_id("id_login").send_keys(user)
	# driver.find_element_by_id("id_password").send_keys(password)
	# driver.find_element_by_id("signin_btn").click()

	# Get the cookies from the site
	# cookies = driver.get_cookies()
	# print(cookies)
	cookies = [{'domain': '.leetcode.com', 'expiry': 1616954810, 'httpOnly': False, 'name': '_gat', 'path': '/', 'secure': False, 'value': '1'}, {'domain': '.leetcode.com', 'httpOnly': True, 'name': 'messages', 'path': '/', 'sameSite': 'Lax', 'secure': True, 'value': '"127a22f8aaedc660c16aaa730717c980435557b7$[[\\"__json_message\\"\\0540\\05425\\054\\"Successfully signed in as DetectivePikachu.\\"]]"'}, {'domain': 'leetcode.com', 'expiry': 1648404351, 'httpOnly': False, 'name': 'csrftoken', 'path': '/', 'sameSite': 'Lax', 'secure': True, 'value': 'y6YM7uH1VNzVibtNtcDmr5mb8IGkKInKtJFPoXsb32yDRsvx3RZJOrmeBNbHGSEL'}, {'domain': '.leetcode.com', 'expiry': 1617041150, 'httpOnly': False, 'name': '_gid', 'path': '/', 'secure': False, 'value': 'GA1.2.1941550211.1616954690'}, {'domain': '.leetcode.com', 'expiry': 1618164349, 'httpOnly': True, 'name': 'LEETCODE_SESSION', 'path': '/', 'sameSite': 'Lax', 'secure': True, 'value': 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMTQ4NjQ4MSIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImRqYW5nby5jb250cmliLmF1dGguYmFja2VuZHMuTW9kZWxCYWNrZW5kIiwiX2F1dGhfdXNlcl9oYXNoIjoiZjE1MDk5ZTc4NTRhZjQ4NjBmMWU3NTAwYTQ4NjE1MmI2ZThjZDY4YSIsImlkIjoxNDg2NDgxLCJlbWFpbCI6ImRpbGxvbi53dUBlbW9yeS5lZHUiLCJ1c2VybmFtZSI6IkRldGVjdGl2ZVBpa2FjaHUiLCJ1c2VyX3NsdWciOiJEZXRlY3RpdmVQaWthY2h1IiwiYXZhdGFyIjoiaHR0cHM6Ly93d3cuZ3JhdmF0YXIuY29tL2F2YXRhci9lZGQ5MGM5ZWRkOWFjMWU5ODBiN2NmNTYyNjFhNmU2YS5wbmc_cz0yMDAiLCJyZWZyZXNoZWRfYXQiOjE2MTY5NTQ3NDksImlwIjoiMTA4LjI5LjE5MC4xNCIsImlkZW50aXR5IjoiM2RjZmUxOWQxZmVjZDcyNzMwMjc0ZGU0MjdiZmQ1NWYiLCJzZXNzaW9uX2lkIjo3NTk4MzYzLCJfc2Vzc2lvbl9leHBpcnkiOjEyMDk2MDB9.TJy51EUkvBFRJwqNqmhD-ntuqXStRVPTPK-cuVlfA4o'}, {'domain': '.leetcode.com', 'expiry': 1680026750, 'httpOnly': False, 'name': '_ga', 'path': '/', 'secure': False, 'value': 'GA1.2.779425684.1616954690'}, {'domain': '.leetcode.com', 'expiry': 1616956489, 'httpOnly': True, 'name': '__cf_bm', 'path': '/', 'sameSite': 'None', 'secure': True, 'value': '7d2c7c880568f1023696311e19b8739fa4b0c13a-1616954689-1800-AfmlZoeByTAhlRzNVvoCiscqKR6vIQJJpnK/UUb6HhVE1bq4ulGGzZjS/jGGPe0lo98r6Lfnr/b0oPBg6SXYUTQ='}, {'domain': '.leetcode.com', 'expiry': 1619546689, 'httpOnly': True, 'name': '__cfduid', 'path': '/', 'sameSite': 'Lax', 'secure': False, 'value': 'de4be27110f0138d7047150b28d3c63481616954689'}]
	for c in cookies: 
		driver.add_cookie(c)

	# time.sleep(10) # Let the user actually see something!

	submissions_url = 'https://leetcode.com/submissions/#/'
	page_num = 1
	count = 0 # keep track of number of solved problems for debugging purposes
	ttl = 15 # time to live value so that if ttl ever reaches 0, then assume we have run out of submissions (or there is some bug)
	while True: 
		try:
			driver.get(submissions_url + str(page_num))
			page = driver.page_source # get the webpage
			html = BeautifulSoup(page, features="html.parser") # transform the webpage into html
			table = html.find("table", {"class":"table table-striped table-bordered table-hover"})
			if table == None:
				ttl -= 1
				time.sleep(2)
				if ttl == 0: break
				continue
			all_rows = table.findAll(lambda tag: tag.name=="tr")
			for row in all_rows:
				all_cols = row.findAll(lambda tag: tag.name=="td")
				# print("all the columns", all_cols)
				# print("all the rows", row)
				if (len(all_cols) == 0): 
					continue
				name = all_cols[1].text[1:].lower().replace(" ", "-")[:-1] # get the name of the problem with some formatting
				accepted = all_cols[2] # get the accepted 
				language = all_cols[4].text
				# if we have not seen this problem before and it is accepted
				if name not in visited and accepted.text == 'Accepted':
					visited[name] = 1
					redirect = accepted.find('a').get('href')
					get_code(driver, redirect, name, language)
					count+=1 	
				
				# we hit something that is in the json file meaning we already have the solution for the code 
				if name in past_problems:
					break
				
			ttl = 15
			print("page " + str(page_num) + " done")	
			page_num += 1
		except Exception as e:
			print(e)
			break

	visited.update(past_problems)
	with open("visited.json", "w") as f:
		json.dump(visited, f)

	time.sleep(5)
	print("final count: ", count)
	driver.quit()

	# Take the most recently accepted submission
	# if not os.path.exists("submitted_problems.json"):
	# 	with open('submitted_problems.json', w) as f:
	# 		json.dump(data, f)


if __name__ == "__main__":
	main()