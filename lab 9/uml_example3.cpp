class User {
	public:
		User(string uname, string pass);
		bool verifyLogin();
		void resetPassword(string newPass);
	protected:
		string username;
		string password;
};

class Admin : public User {
	public:
		Admin(string uname, string pass);
		bool updateSystem();
};
