/*
*
*  MIT License
*
*  Copyright (c) 2017 finixbit <finix@protonmail.com>
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
*
*
*/

#include <iostream>
#include "../gearman_client.h"


int main(int argc, char* argv[]) {

  std::string gearmanHost("127.0.0.1");
  int gearmanPort = 4730;

  GearmanCxxClient gmClient(gearmanHost, gearmanPort);

  if(gmClient.gearmanConnIsInvalid()) {
    std::cout << "Connection Failed ..." << std::endl;
    return 1;
  }

  std::string gearmanTaskName("reverse_str");
  std::string data("Hello world");
  bool waitTillComplete = true;

  // send normal job
  std::string result = gmClient.gearmanSendJob(gearmanTaskName, data);
  std::cout << "result from worker: " << result << std::endl;

  // send background job
  printf("sending background job ...\n");
  bool response = gmClient.gearmanSendJobBackground(gearmanTaskName, data);
  if(response)
   std::cout << "background job successful ..." << std::endl;

  return 0;
}