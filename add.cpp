/* Sum comma separated lists of numbers element wise.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string const help =
   "Sum comma separated lists of numbers element wise.\n"
   "\nUsage:\n"
   "\tadd list1 list2 list3 ...\n"
   "\nOutput: The sum of the lists as a comma separated list.\n"
   "\nAll lists must have the same length.";


int main(int argc, char** argv)
{
   if (argc == 1){
      std::cout << help << std::endl;
      return(1);
   }
   std::vector<double> sum;
   std::stringstream csv1(argv[1]);
   for (double value; csv1 >> value;) {
      sum.push_back(value);
      if (csv1.peek() == ',') {
         csv1.ignore(1);
      }
   }
   double value;
   for (int i = 2; i < argc; i++){
      std::stringstream csv(argv[i]);
      for (double &element : sum) {
         if (csv.good()) csv >> value;
         else {
            std::string msg =
               "List " + std::to_string(i-1) + " has too few elements.";
            std::cerr << msg << std::endl;
            return EXIT_FAILURE;
         }
         element += value;
         if (csv.peek() == ',') {
            csv.ignore(1);
         }
      }
      if (!csv.eof()) {
         std::string msg =
            "List " + std::to_string(i-1) + " has too many elements.";
         std::cerr << msg << std::endl;
         return EXIT_FAILURE;
      }
   }
   bool first = true;
   for (double const &element : sum) {
      if (!first) std::cout << ',';
      std::cout << element;
      first = false;
   }
   std::cout << std::endl;

   return 0;
}
