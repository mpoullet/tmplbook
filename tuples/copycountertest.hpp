void copycountertest()
{
  Tuple<CopyCounter<0>, CopyCounter<1>, CopyCounter<2>, 
        CopyCounter<3>, CopyCounter<4>> copies;
  auto reversed = reverse(copies);
  std::cout << "0: " << CopyCounter<0>::numCopies << " copies\n";
  std::cout << "1: " << CopyCounter<1>::numCopies << " copies\n";
  std::cout << "2: " << CopyCounter<2>::numCopies << " copies\n";
  std::cout << "3: " << CopyCounter<3>::numCopies << " copies\n";
  std::cout << "4: " << CopyCounter<4>::numCopies << " copies\n";
}
