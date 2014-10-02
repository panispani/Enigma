#!/usr/bin/python
from subprocess import Popen, PIPE, STDOUT
import os.path
import sys

#-------------- test cases --------------#

basic_test_data = [ 
  #config error checking
  ("No Such Plugboard Config File Test", "", ["plugboards/nulll.pb"], "", "FAIL"),

  #minimal config checking
  ("Minimal Config Test", "", ["plugboards/null.pb"], "", "PASS"),

  #basic IO checking
  ("Basic Rotor I/O Test", "A",["rotors/I.rot","plugboards/I.pb"], "N", "PASS"),
  ("Invalid Input Test", "a", ["rotors/I.rot","plugboards/I.pb"], "N", "FAIL"),

  #first char map checking
  ("First Char Mapping Test 1", "A", ["rotors/I.rot","plugboards/null.pb"], "N", "PASS"),
  ("First Char Mapping Test 2", "B", ["rotors/II.rot","plugboards/I.pb"], "M", "PASS"),
  ("First Char Mapping Test 3", "C", ["rotors/VII.rot","plugboards/I.pb"], "D", "PASS"),
  ("First Char Mapping Test 4", "D", ["rotors/III.rot","rotors/VII.rot","plugboards/II.pb"], "X", "PASS"),
] 

advanced_test_data = [ 
  #full reflector functionality checking
  ("Full Reflector Test", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", ["plugboards/null.pb"] ,"NOPQRSTUVWXYZABCDEFGHIJKLM", "PASS"),

  #full plugboard functionality checking
  ("Full Plugbaord Test 1", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", ["plugboards/I.pb"], "NOPQRSTUMWXYIABCDEFGHZJKLV", "PASS"), 
  ("Full Plugbaord Test 2", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", ["plugboards/II.pb"], "NOPQISTUEWMYKABCDVFGHRJZLX", "PASS"),
  
  #full basic rotor functionality checking
  ("Full Basic Rotor Test 1", "AAAAAAAAAAAAAAAAAAAAAAAAAA", ["rotors/I.rot", "plugboards/null.pb"], "NNNNNNNNNNNNNNNNNNNNNNNNNN", "PASS"),
  ("Full Basic Rotor Test 2", "AAAAAAAAAAAAAAAAAAAAAAAAAA", ["rotors/II.rot", "plugboards/null.pb"], "PLPLPLPLPLPLPLPLPLPLPLPLPL", "PASS"),

  #full complex rotor functionality checking
  ("Full Rotor Test 1", "AAAAAAAAAAAAAAAAAAAAAAAAAA", ["rotors/III.rot", "plugboards/null.pb"], "LLFORJEVOKWPPKRFJMGQVJMQUR", "PASS"),
  ("Full Rotor Test 2", "DDDDDDDDDDDDDDDDDDDDDDDDDD", ["rotors/IV.rot", "plugboards/null.pb"], "KYRVLIQWULYGVOAGPVAQGLIASM", "PASS"),
  ("Full Rotor Test 3", "KLKLKLKLKLKLKLKLKLKLKLKLKL", ["rotors/V.rot", "plugboards/null.pb"], "PKJSRUTBANMJIWVSRNMJISRVUQ", "PASS"),

  #full rotor cascade checking
  ("Rotor Cascade Test 1", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 
         ["rotors/I.rot", "rotors/II.rot", "plugboards/null.pb"], 
         "LLLLLLLLLLLLLLLLLLLLLLLLLLPPPPPPPPPPPPPPPPPPPPPPPPPP", "PASS"), 
  ("Rotor Cascade Test 2", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 
         ["rotors/I.rot", "rotors/II.rot", "plugboards/IV.pb"], 
         "ZZZZZZZZZZZZZZZZZZZZZZZZZZXXXXXXXXXXXXXXXXXXXXXXXXXX", "PASS"), 
  ("Rotor Cascade Test 3", "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ",
         ["rotors/II.rot", "rotors/II.rot", "plugboards/null.pb"],
         "NSPURWTYVAXCZEBGDIFKHMJOLQROTQVSXUZWBYDAFCHEJGLINKPM", "PASS"),
  ("Rotor Cascade Test 4", "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ",
         ["rotors/II.rot", "rotors/II.rot", "plugboards/III.pb"],
         "NQLWRUTCKVIYUEBGFXDKMJHRPSROPSVQIWGZBCQAFYMEHGNXLVTJ", "PASS"),
  ("Rotor Cascade Test 5", "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ",
         ["rotors/VI.rot", "rotors/IV.rot", "plugboards/II.pb"],
         "MGDSBKVCZTGFAGSJKPFDIZGIGMFHLWODQOXBJBWIPZHQMCZUDJSN", "PASS")
]

unzip_call = Popen(["gunzip", "-c", "moby.txt.gz"], stdout=PIPE)
moby = unzip_call.communicate()[0]

robust_test_data = [
  #robustness testing (will only pass if the implementation is "spot on")
  ("Robustness Test 1", moby, ["rotors/III.rot", "rotors/VII.rot", "plugboards/II.pb"],
   "0315f65c4d79ad398a2c59ab638b81ba8fe34480bb8cce49cbe3908065c12527  -", "PASS")
]


#----------- helper functions -----------#
def check(name):
  if not os.path.exists(name) :
    print "Cannot find ", name, ", automated test aborted."
    sys.exit(-1)


def run_tests(test_data, check_sha):
  num_tests = len(test_data)
  passed = 0

  for test_case in test_data:
    test_name = test_case[0]
    message = test_case[1]
    settings = test_case[2]
    expected = test_case[3]
    test_type = test_case[4]

    enigma_call = Popen(["./enigma"] + settings, stdin=PIPE, stdout=PIPE, stderr=STDOUT)
    output = enigma_call.communicate(message)
    status = enigma_call.returncode

    actual = output[0].strip('\n')

    inverse_call = Popen(["./enigma"] + settings, stdin=PIPE, stdout=PIPE, stderr=STDOUT)
    output = inverse_call.communicate(actual)
    
    inverse = output[0].strip('\n')
    inverse_error = (inverse != message)

    if check_sha:
      message = "moby.txt.gz"
      sha_call = Popen(["sha256sum"], stdin=PIPE, stdout=PIPE)      
      actual = sha_call.communicate(actual)[0].strip('\n')

    if test_type == "PASS" and ( actual != expected or status != 0 or (inverse_error and not check_sha) ):
      print "\nFAILED: ", test_name
      print "(Your enigma program should pass this test case)"
      print "  config:",
      for arg in ["./enigma"] + settings:
        print arg, 
      print ""
      print "  input:    ", message 
      print "  expected: ", expected
      print "  actual:   ", actual
      if not check_sha:
        print "  self inverse:", not inverse_error
      print "  exit code:", status
    elif test_type == "FAIL" and actual == expected and status == 0:
      print "\nFAILED: ", test_name
      print "(Your enigma program should produce an error in this test case)"
      print "  config:",
      for arg in ["./enigma"] + settings:
        print arg, 
      print ""
      print "  input:        ", message 
      print "  not expecting:", expected
      print "  actual:       ", actual
      print "  exit code:    ", status
    else:
      passed += 1
  return (passed,num_tests)
    
    


#----------- Main Test Script -----------#
print "---- Automated testing for the C++ Enigma exercise ----\n"

#compile the student's submission
print "> Running make:"
make_cmd = Popen(["make"], stdout=PIPE, stderr=STDOUT)
output = make_cmd.communicate()
status = make_cmd.returncode

print output[0]

if status != 0:
  print "Failed to compile, automated test aborted."
  sys.exit(-1)

#check binary was created and config files exist
check("enigma")
check("rotors")
check("plugboards")


#run the tests
print "> Running basic tests:"
basic_results = run_tests(basic_test_data, False)

print "> Running advanced tests:"
adv_results = run_tests(advanced_test_data, False)

print "> Running robustness tests:\n"
robust_results = run_tests(robust_test_data, True)

#print test summary
print "Automated Test Summary:"
print "  Basic Tests:     ", basic_results[0], "/", basic_results[1] 
print "  Advanced Tests:  ", adv_results[0], "/", adv_results[1]
print "  Robustness Tests:", robust_results[0], "/", robust_results[1]
