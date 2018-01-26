struct Person {
  std::string firstName;
  std::string lastName;

  friend std::ostream& operator<<(std::ostream& strm, Person const& p) {
    return strm << p.lastName << ", " << p.firstName;
  }
};
