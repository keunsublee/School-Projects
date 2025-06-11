/*==================================================
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
==================================================*/
import React, { useState } from 'react';
import { Navigate } from 'react-router-dom';
import { Link } from 'react-router-dom';

const LogIn = ({ user, mockLogIn }) => {
  const [userInfo, setUserInfo] = useState({
    userName: user.userName,
    password: ''
  });
  const [navigate, setNavigate] = useState(false);

    // When User Name input is changed, capture the new input value and update state
  const handleChange = (e) => {
    setUserInfo({
      ...userInfo,
      userName: e.target.value
    });
  };

    // When user clicked "Log In" button, store user data and then redirect to "User Profile" page
  const handleSubmit = (e) => {
    e.preventDefault();
    mockLogIn(userInfo);
    setNavigate(true);
  };

  // Redirect to "User Profile" page when "Log In" button is clicked
  if (navigate) {
    return <Navigate to="/userProfile" />;
  }

  // Render the login form (and call "handleSubmit" method when "Log In" button is clicked to submit form)
  return (
    <div>
      <h1>Login</h1>
      
      <form onSubmit={handleSubmit}>
        <div>
          <label>User Name</label>
          <input type="text" name="userName" defaultValue={user.userName} onChange={handleChange} />
        </div>
        <div>
          <label>Password</label>
          <input type="password" name="password" />
        </div>
        <button>Log In</button>
      </form>

      <br />
      <Link to="/">Return to Home</Link>
    </div>
  );
};

export default LogIn;
