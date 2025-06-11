/*==================================================
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
==================================================*/
import React from 'react';
import { Link } from 'react-router-dom';

const UserProfile = ({ accountBalance, userName, memberSince }) => {
  return (
    <div>
      <h1>User Profile</h1>

      <div>Username: {userName}</div>
      <div>Member Since: {memberSince}</div>
      <br />
      <Link to="/">Return to Home</Link>
    </div>
  );
};

export default UserProfile;
