---
title: sql injection
---

SQL Injection (SQLi) is a type of security vulnerability that occurs when an attacker is able to manipulate a web application's SQL query by injecting malicious SQL code. This can lead to unauthorized access, data manipulation, and potential exposure of sensitive information stored in a database. SQL injection attacks are particularly dangerous and common, making them a significant concern for web application security.

**How SQL Injection Occurs:**

1. **User Input in SQL Queries:**
   - Web applications often use user input to construct SQL queries dynamically. This input may come from form fields, URL parameters, or any other user-controlled input.

2. **Failure to Sanitize Input:**
   - If the web application does not properly validate, sanitize, or escape user input before incorporating it into SQL queries, attackers can inject malicious SQL code.

3. **Manipulating SQL Queries:**
   - Attackers insert specially crafted SQL statements into user input fields to manipulate the intended SQL query. This can include altering the query's logic, extracting data, or performing unauthorized actions.

**Common Examples of SQL Injection:**

1. **Classic SQL Injection:**
   - In this scenario, an attacker appends or injects SQL code into input fields. For example, altering a login form to bypass authentication.

   ```
   Username: ' OR '1'='1'; --
   Password: (empty or any value)
   ```

   The resulting SQL query might look like:

   ```sql
   SELECT * FROM users WHERE username = '' OR '1'='1'; --' AND password = '';
   ```

2. **Union-Based SQL Injection:**
   - Attackers use the `UNION` SQL operator to combine results from different queries. This can be used to extract data from other tables.

   ```
   id=1' UNION SELECT 1, username, password FROM users; --
   ```

   The injected SQL might look like:

   ```sql
   SELECT * FROM products WHERE id = '1' UNION SELECT 1, username, password FROM users; --
   ```

3. **Time-Based Blind SQL Injection:**
   - Attackers exploit conditional statements in the SQL query to infer information. This involves injecting time-delayed queries.

   ``` 
   id=1' AND IF(1=1, SLEEP(5), 0); --
   ```

   The attacker observes if the application introduces a delay, indicating a true condition.

**Mitigation and Prevention:**

1. **Parameterized Queries (Prepared Statements):**
   - Use parameterized queries or prepared statements provided by your web framework or database API. These techniques separate user input from SQL code and prevent injection.

2. **Input Validation and Sanitization:**
   - Implement strict input validation to ensure that user input adheres to expected formats. Sanitize input to remove potentially harmful characters.

3. **Least Privilege Principle:**
   - Limit database user privileges to the minimum necessary for the application to function. Avoid using accounts with broad permissions.

4. **Web Application Firewall (WAF):**
   - Implement a Web Application Firewall that can detect and block SQL injection attempts.

5. **Regular Security Audits:**
   - Conduct regular security audits and penetration testing to identify and address vulnerabilities in your web application.

6. **Educate Developers:**
   - Train developers on secure coding practices, emphasizing the importance of validating and properly handling user input.