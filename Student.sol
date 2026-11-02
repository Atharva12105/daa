// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData{
    struct Student{
        string name;
        uint256 rollno;
    }

    Student [] public studentarr;

    //add student
    function addStudent(string memory name,uint256 roll)public {
        for(uint i=0;i<studentarr.length;i++){
            if(studentarr[i].rollno==roll){
                revert("Roll no already exists!");
            }
        }
        studentarr.push(Student(name,roll));
    }

    //number of students
    function getStudentLength() public view returns(uint){
        return studentarr.length;
    }

    //display all students
    function Display() public view returns(Student[] memory) {
        return studentarr;
    }

    // get student by index
    function getStudent(uint index) public view returns(Student memory){
        require(index<studentarr.length,"Invalid index!");
        return studentarr[index];
    }

    //fallback
    fallback() external payable {
        revert("Please use the functions provided!");
     }
     //receive
    receive() external payable {
        revert("Please use the functions provided!");
    }
}