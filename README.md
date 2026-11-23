# Student Record Management System in C

A console-based **Student Record Management System** developed using the C programming language. This project demonstrates the implementation of CRUD (Create, Read, Update, and Delete) operations using both text file and binary file handling techniques.

The system allows users to manage student information, including Student ID, Name, Department, and CGPA. It provides two separate file-handling approaches to demonstrate how structured data can be stored, accessed, modified, and deleted in C.

---

## Group Information

**Group: 06**

| Member | Name | Student ID |
|---|---|---|
| Member 1 | Farhana Sultana | 253-35-251 |
| Member 2 | Nusrat Zahan Nipu | 253-35-497 |
| Member 3 | Khairunnahar Parthee | 253-35-140 |

---

## Table of Contents

- [Project Overview](#project-overview)
- [Objectives](#objectives)
- [Key Features](#key-features)
- [System Modules](#system-modules)
- [Student Data Structure](#student-data-structure)
- [File Handling Implementation](#file-handling-implementation)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [Installation and Execution](#installation-and-execution)
- [Sample Student Records](#sample-student-records)
- [Learning Outcomes](#learning-outcomes)
- [Limitations](#limitations)
- [Conclusion](#conclusion)

---

## Project Overview

The Student Record Management System is designed to provide a simple and organized way to manage student records through a menu-driven console application.

The project implements two different file storage mechanisms:

1. **Text File Handling:** Stores student records in a human-readable text format.
2. **Binary File Handling:** Stores student records in binary format using structures.

Both implementations support the four fundamental CRUD operations.

---

## Objectives

The primary objectives of this project are:

- To implement CRUD operations using C programming.
- To understand file handling techniques in C.
- To demonstrate the differences between text and binary file storage.
- To practice reading and writing structure data.
- To understand file pointers and file access modes.
- To develop practical programming skills through a real-world record management application.

---

## Key Features

| Feature | Description |
|---|---|
| Create Student | Add new student records to a file. |
| Read Students | Display all stored student records. |
| Update Student | Modify an existing record using Student ID. |
| Delete Student | Remove a record using Student ID. |
| Text File Operations | Manage records using text files. |
| Binary File Operations | Manage records using binary files. |
| Menu-Driven Interface | Navigate through different operations using menus. |

---

## System Modules

The application is divided into two major modules.

### 1. Text File Operations

This module manages student information using a text file named `students.txt`.

**Available Operations:**

- Create Student
- Read Students
- Update Student
- Delete Student
- Return to Main Menu

### 2. Binary File Operations

This module manages student information using a binary file named `students.dat`.

**Available Operations:**

- Create Student
- Read Students
- Update Student
- Delete Student
- Return to Main Menu

---

## Student Data Structure

The system uses a C structure named `Student` to organize student information.

```c
struct Student
{
    int id;
    char name[50];
    char department[50];
    float cgpa;
};
```

Each student record contains the following fields:

| Field | Data Type | Description |
|---|---|---|
| id | int | Unique student identification number |
| name | char[50] | Student's name |
| department | char[50] | Student's department |
| cgpa | float | Student's CGPA |

---

## File Handling Implementation

### Text File Handling

Student records are stored in `students.txt` in a readable text format.

**File Handling Functions:**

| Function | Purpose |
|---|---|
| `fopen()` | Opens a file. |
| `fprintf()` | Writes formatted data to a file. |
| `fscanf()` | Reads formatted data from a file. |
| `fclose()` | Closes an opened file. |
| `remove()` | Deletes an existing file. |
| `rename()` | Renames a temporary file. |

**File Access Modes:**

| Mode | Purpose |
|---|---|
| `"a"` | Opens a file for appending records. |
| `"r"` | Opens a file for reading. |
| `"w"` | Opens a file for writing. |

### Binary File Handling

Student records are stored in `students.dat` in binary format.

**File Handling Functions:**

| Function | Purpose |
|---|---|
| `fopen()` | Opens a binary file. |
| `fwrite()` | Writes structure data to a file. |
| `fread()` | Reads structure data from a file. |
| `fclose()` | Closes an opened file. |
| `fseek()` | Moves the file pointer to a specified position. |
| `remove()` | Deletes an existing file. |
| `rename()` | Renames a temporary file. |

**File Access Modes:**

| Mode | Purpose |
|---|---|
| `"ab"` | Opens a binary file for appending. |
| `"rb"` | Opens a binary file for reading. |
| `"rb+"` | Opens a binary file for reading and updating. |
| `"wb"` | Opens a binary file for writing. |

---

## Technologies Used

| Technology | Purpose |
|---|---|
| C Programming | Main programming language |
| GCC | Compiler |
| Code::Blocks | Development environment |
| Visual Studio Code | Code editor |
| Text File Handling | Text-based data storage |
| Binary File Handling | Binary data storage |

**Core Concepts:** Structures, Functions, Pointers, File I/O, and CRUD Operations.

---

## Project Structure

The repository can be organized as follows:

```text
Student-Record-Management-System/
│
├── student_record.c
├── README.md
├── students.txt
└── students.dat
```

**Note:** The data files `students.txt` and `students.dat` are generated when records are created. They do not need to be uploaded beforehand.

---

## Installation and Execution

### Prerequisites

Before running the project, make sure you have:

- GCC compiler installed.
- Code::Blocks or Visual Studio Code.
- A basic understanding of C programming.

### Step 1: Clone the Repository

```bash
git clone YOUR_REPOSITORY_URL
```

### Step 2: Navigate to the Project Directory

```bash
cd Student-Record-Management-System
```

### Step 3: Compile the Source Code

```bash
gcc student_record.c -o student_record
```

### Step 4: Run the Application

**Windows:**

```bash
student_record.exe
```

**Linux / macOS:**

```bash
./student_record
```

**Note:** Replace `student_record.c` with the actual source filename if it is different.

---

## Sample Student Records

The following table illustrates sample student information that can be entered into the system.

| Student ID | Name | Department | CGPA |
|---|---|---|---|
| 101 | Farhana | SWE | 3.46 |
| 102 | Nusrat | SWE | 3.56 |
| 103 | Parthee | CSE | 3.76 |
| 104 | Inaya | BBA | 3.50 |

*These records are provided for demonstration purposes only.*

---

## Learning Outcomes

By completing this project, we gained practical experience in:

- Implementing CRUD operations in C.
- Understanding text and binary file handling.
- Working with structures and functions.
- Reading and writing structured data.
- Using `fread()` and `fwrite()`.
- Managing file pointers and file access modes.
- Updating records using `fseek()`.
- Handling temporary files using `remove()` and `rename()`.
- Developing a menu-driven console application.

---

## Limitations

- The application operates through a console-based interface.
- Student names and department names are currently read as single words.
- The system does not include authentication or user roles.
- Data is stored locally in text and binary files.
- Duplicate Student IDs are not currently prevented.

---

## Conclusion

The Student Record Management System successfully demonstrates the implementation of CRUD operations using text and binary file handling in C.

Through this project, we explored fundamental programming concepts, including structures, functions, file pointers, and file input/output operations.

The project provides a practical foundation for understanding data management and file handling techniques in C programming.

---

**Developed as an academic project using the C programming language.**

