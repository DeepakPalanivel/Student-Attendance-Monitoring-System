📋 Student Attendance Monitoring System
This is a simple C-based console application for managing student attendance records. It allows users to add, delete, search, and display attendance data, with additional features like reverse display and cloning for administrative review.
🛠 Features
- ➕ Add attendance records
- ❌ Delete incorrect entries
- 🔍 Search attendance by student ID and date
- 📅 Display attendance for a specific date
- 🔄 Reverse display of all records
- 📋 Clone attendance list for admin review
📦 Data Structure
The system uses a singly linked list to store attendance records. Each record includes:
- studentID: Integer representing the student
- date: String in dd-mm-yyyy format
- status: Either "Present" or "Absent"
- next: Pointer to the next record
🚀 How to Run
- Clone the repository:
git clone https://github.com/your-username/attendance-monitoring.git
cd attendance-monitoring
- Compile the code:
gcc attendance.c -o attendance
- Run the program:
./attendance


📋 Menu Options
|  |  | 
|  |  | 
|  |  | 
|  |  | 
|  |  | 
|  |  | 
|  |  | 
|  |  | 


📎 Example Usage
--- Student Attendance Monitoring ---
1. Add Record
2. Delete Record
3. Search Record
4. Display by Date
5. Reverse Display
6. Clone List for Admin
7. Exit
Enter choice: 1
Enter ID, Date (dd-mm-yyyy), Status (Present/Absent): 101 26-10-2025 Present
Record added successfully!


📁 File Structure
attendance-monitoring/
├── attendance.c      # Main source code
├── README.md         # Project documentation


🧠 Notes
- All records are stored in memory during runtime.
- The cloned list is a deep copy and can be used for administrative review or backup.
- No persistent storage (e.g., file or database) is implemented.
📜 License
This project is open-source and available under the MIT License.
