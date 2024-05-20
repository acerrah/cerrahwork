---
title: mongodb
---
MongoDB is a widely used, open-source NoSQL (Not Only SQL) database management system that provides high performance, flexibility, and scalability. Unlike traditional relational databases, MongoDB stores data in a flexible, JSON-like format called BSON (Binary JSON), which allows for the efficient storage and retrieval of documents.

MongoDB provides a command-line interface called `mongo` for interacting with the database. Below are some basic terminal commands for MongoDB:

1. **Connect to MongoDB Server:**
   ```bash
   mongo
   ```
   - This command opens a connection to the default MongoDB server running on `localhost` on the default port (`27017`).

2. **Connect to a Specific MongoDB Server and Port:**
   ```bash
   mongo --host <hostname> --port <port>
   ```
   - Replace `<hostname>` with the MongoDB server's hostname or IP address, and `<port>` with the desired port number.

3. **Show Databases:**
   ```bash
   show dbs
   ```
   - Lists all the databases on the MongoDB server.

4. **Switch to a Database:**
   ```bash
   use <database>
   ```
   - Switches to the specified database. If the database does not exist, MongoDB will create it when you insert data.

5. **Show Collections in the Current Database:**
   ```bash
   show collections
   ```
   - Displays all the collections (similar to tables in relational databases) in the current database.

6. **Insert a Document into a Collection:**
   ```bash
   db.<collection>.insert({ key: "value" })
   ```
   - Inserts a document into the specified collection.

7. **Query Documents in a Collection:**
   ```bash
   db.<collection>.find()
   ```
   - Retrieves all documents in the specified collection.

8. **Query Documents with a Filter:**
   ```bash
   db.<collection>.find({ key: "value" })
   ```
   - Retrieves documents in the specified collection that match the given filter criteria.

9. **Update a Document in a Collection:**
   ```bash
   db.<collection>.update({ key: "value" }, { $set: { newKey: "newValue" } })
   ```
   - Updates a document in the specified collection based on the filter criteria.

10. **Remove Documents from a Collection:**
    ```bash
    db.<collection>.remove({ key: "value" })
    ```
    - Removes documents from the specified collection based on the filter criteria.

11. **Create an Index:**
    ```bash
    db.<collection>.createIndex({ key: 1 })
    ```
    - Creates an index on the specified key in the collection to improve query performance.

12. **Exit the MongoDB Shell:**
    ```bash
    exit
    ```
    - Exits the MongoDB shell.
