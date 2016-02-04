# firstworkingproto

var functionfactory = require('./build/Release/xmsbridge');
var asyncWorker = require('./build/Release/xmsbridgeAsync');

var messageListener1 = functionfactory.CreateListenerConfig(
  "ServCon","localhost","1414","QM_idea_PC","queue://sample","theThree",
  function(err,val){
      console.log("dandanakka");
      console.log(val);
      var req = http.request(options, callback);
      req.write(val);
      req.end();
  });

functionfactory.StartListener(messageListener1);

asyncWorker.asyncReceiver("ServCon","localhost","1414","QM_idea_PC","queue://default",function(err,val){
     console.log("so so so");
     console.log("Done here");
     response.writeHead(200, { "Content-Type": "text/plain" });
     response.end("...............Good");
	   response = null;
  });

Include
C:\Program Files (x86)\IBM\WebSphere MQ\tools\cplus\include
C:\Program Files (x86)\IBM\WebSphere MQ\tools\c\include

Lib

C:\Program Files (x86)\IBM\WebSphere MQ\tools\lib64

C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A

F:\IBM\XMS\bin64

Path

C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A

C:\Program Files (x86)\IBM\WebSphere MQ\bin64

WindowsSdkDir
C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Lib
