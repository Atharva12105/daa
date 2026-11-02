// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Bank{
    uint256 balance=0;
    address public accountOwner;

    constructor(){
        accountOwner=msg.sender;
    }

    //Deposit
    function Deposit() public payable {
        require(accountOwner==msg.sender,"You are not an Account Owner");
        require(msg.value>0,"Amount should be greater than 0!");
        balance+=msg.value;
    }

    //Withdraw
    function Withdraw() public payable{
        require(accountOwner==msg.sender,"You are not an account owner");
        require(msg.value>0,"Withdrawal amount should be greater than 0");
        balance-=msg.value;
    }

    //showbalance
    function showBalance() public view returns(uint256){
      require(accountOwner==msg.sender,"You are not an account owner");
      return balance;
    }
}