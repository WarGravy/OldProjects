#include <iostream>
#include <fstream>
#include <string>
#include "htmlzack.h"
using namespace std;
//global
string HTML_NAME;

//constructors
htmlzack::htmlzack(string temp){
	HTML_NAME = temp;
	hout.clear();
	hout.open(HTML_NAME.c_str());
	hout.clear();
	initialize();
	
}
	htmlzack::~htmlzack(){
	end();
	hout.close();
	hout.clear();
}
//public
//Tables
void htmlzack::insertTableHead(std::string temp){
	//<table border = "5" width = "800" align="center">
	hout<<"    <table border = "<<'"'<<'5'<<'"'<<" width = "<<'"'<<"800"<<'"'<<" align="<<'"'<<"center"<<'"'<<'>'<<endl;
	//<tr>
	hout<<"    <tr>"<<endl;
		//<th> string here </th>
	hout<<"        <th>"<<temp<<"</th>"<<endl;

	//</tr>
	hout<<"    </tr>"<<endl;
}
void htmlzack::insertRow(std::string temp){
	//<tr>
	hout<<"    <tr>"<<endl;
		//<td> string here </td>
	hout<<"        <td>"<<temp<<"</td>"<<endl;

	//</tr>
	hout<<"    </tr>"<<endl;
}
void htmlzack::insertRow(std::string temp, int temp2){
	//<tr>
	hout<<"    <tr>"<<endl;
		//<td> string here : int here </td>
	hout<<"        <td>"<<temp<<": "<<temp2<<"</td>"<<endl;

	//</tr>
	hout<<"    </tr>"<<endl;
}
void htmlzack::insertRow(std::string temp, int temp2, int percent){
	//<tr>
	hout<<"    <tr>"<<endl;
		//<td> string here : int here </td>
	hout<<"        <td>"<<temp<<": "<<temp2<<" ("<<percent<<"%)"<<"</td>"<<endl;

	//</tr>
	hout<<"    </tr>"<<endl;
}	
void htmlzack::endTable(){
hout <<"</table>"<<endl;
hout<<"<p><br/></p>"<<endl;
}
//Lists
void htmlzack::insertListHead(std::string temp, std::string temp2){
		//<p><b> string here </b></p>
	hout<<"        <p><b>"<<temp<<"</b><br />"<<temp2<<"</p>"<<endl;
	//<ul>
	hout<<"<ul>"<<endl;
}
void htmlzack::insertListStartTag(){
	//<ul>
	hout<<"<ul>"<<endl;
}
void htmlzack::insertListEndTag(){
	//<ul>
	hout<<"</ul>"<<endl;
}
void htmlzack::insertList(std::string temp){
		//<li> string here </li>
	hout<<"        <li>"<<temp<<"</li>"<<endl;

}
void htmlzack::insertListLink(std::string temp, std::string link, int unused, int bad){
		//<li><a href="link"> string here </a></li>
	hout<<"        <li><a href="<<'"'<<link<<'"'<<'>'<<temp<<" ("<<unused<<'/'<<bad<<')'<<"</a></li>"<<endl;

}
void htmlzack::insertListLinkW(std::string temp, std::string link){
		//<li><a href="link" onclick="window.open(this.href,'_blank'); return false;"> string here </a></li>
	hout<<"        <li><a href="<<'"'<<link<<'"'<<"onclick="<<'"'<<"window.open(this.href,'_blank'); return false;"<<'"'<<'>'<<temp<<"</a></li>"<<endl;

}
void htmlzack::insertListLink(std::string temp, std::string link){
		//<li><a href="link"> string here </a></li>
	hout<<"        <li><a href="<<'"'<<link<<'"'<<'>'<<temp<<"</a></li>"<<endl;

}
void htmlzack::insertListR(std::string temp){
		//<li style="color: #F00;"> string here </li>
	hout<<"        <li style="<<'"'<<"color: #F00;"<<'"'<<'>'<<temp<<"</li>"<<endl;

}
void htmlzack::insertList(std::string temp, int temp2){
		//<li> string here : int here </li>
	hout<<"        <li>"<<temp<<": "<<temp2<<"</li>"<<endl;

}
	
void htmlzack::endList(){
hout <<"</ul>"<<endl;
hout<<"<p><br/></p>"<<endl;
}
//private
void htmlzack::initialize(){
	/*<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">*/
	hout<<"<!DOCTYPE html PUBLIC "<<'"'<<"-//W3C//DTD XHTML 1.0 Transitional//EN"<<'"'<<' '<<'"'<<"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"<<'"'<<'>'<<endl;
	/*<html xmlns="http://www.w3.org/1999/xhtml">*/
	hout <<"<html xmlns="<<'"'<<"http://www.w3.org/1999/xhtml"<<'"'<<'>'<<endl;
	//<title>The Digital Intern Report</title>
hout <<"<title>The Digital Intern Report</title>"<<endl;
	//<head>
	hout<<"    <head>"<<endl;
	//<link href="reset.css" rel="stylesheet" type="text/css" media="screen" />
	if(HTML_NAME.compare("report/index.html") == 0){
	hout<<"<link href="<<'"'<<"reset.css"<<'"'<<" rel="<<'"'<<"stylesheet"<<'"'<<" type="<<'"'<<"text/css"<<'"'<<" media="<<'"'<<"screen"<<'"'<<" />"<<endl;
	}
	else if(HTML_NAME.compare("report/index2.html") == 0){
	hout<<"<link href="<<'"'<<"reset.css"<<'"'<<" rel="<<'"'<<"stylesheet"<<'"'<<" type="<<'"'<<"text/css"<<'"'<<" media="<<'"'<<"screen"<<'"'<<" />"<<endl;
	}
	else if(HTML_NAME.compare("report/index3.html") == 0){
	hout<<"<link href="<<'"'<<"reset.css"<<'"'<<" rel="<<'"'<<"stylesheet"<<'"'<<" type="<<'"'<<"text/css"<<'"'<<" media="<<'"'<<"screen"<<'"'<<" />"<<endl;
	}
	else{
	hout<<"<link href="<<'"'<<"../reset.css"<<'"'<<" rel="<<'"'<<"stylesheet"<<'"'<<" type="<<'"'<<"text/css"<<'"'<<" media="<<'"'<<"screen"<<'"'<<" />"<<endl;
	}
		//<style>
		hout<<"        <style>"<<endl;
			//th { color: #ffffff }
			hout<<"            th { color: #003366 }"<<endl;
			//td { color: #00ff18 }
			hout<<"            td { color: #000000 }"<<endl;
			//li { color: #ffffff }
			hout<<"            li { color: #000000 }"<<endl;
			//p { color: #00ff18 }
			hout<<"            p { color: #003366 }"<<endl;
		//</style>
		hout<<"        </style>"<<endl;
	//</head>
	hout<<"    </head>"<<endl;
//<body align="center">
hout<<"<body "<<" align="<<'"'<<"center"<<'"'<<'>'<<endl;
	//<div style="width:100%; text-align:center">
	hout<<"    <div style="<<'"'<<"width:100%; text-align:center"<<'"'<<'>'<<endl;
	//<a href="report.html"><img src="images/logo.png" alt="The Digital Intern Developed By Zachary Carlson"></a>
	if(HTML_NAME.compare("report/index.html") == 0){
	hout<<"<a href="<<'"'<<"index.html"<<'"'<<'>'<<"<img src="<<'"'<<"images/logo.png"<<'"'<<" alt="<<'"'<<"The Digital Intern Developed By Zachary Carlson"<<'"'<<"></a>"<<endl;
	}
	else if(HTML_NAME.compare("report/index2.html") == 0){
	hout<<"<a href="<<'"'<<"index.html"<<'"'<<'>'<<"<img src="<<'"'<<"images/logo.png"<<'"'<<" alt="<<'"'<<"The Digital Intern Developed By Zachary Carlson"<<'"'<<"></a>"<<endl;
	}
	else if(HTML_NAME.compare("report/index3.html") == 0){
	hout<<"<a href="<<'"'<<"index.html"<<'"'<<'>'<<"<img src="<<'"'<<"images/logo.png"<<'"'<<" alt="<<'"'<<"The Digital Intern Developed By Zachary Carlson"<<'"'<<"></a>"<<endl;
	}
	else{
	hout<<"<a href="<<'"'<<"../index.html"<<'"'<<'>'<<"<img src="<<'"'<<"../images/logo.png"<<'"'<<" alt="<<'"'<<"The Digital Intern Developed By Zachary Carlson"<<'"'<<"></a>"<<endl;
	}
	//<p><br/></p> 
	hout<<"    <p><br/></p>"<<endl;
	//</div>
	hout<<"    </div>"<<endl;
}
void htmlzack::end(){
//<img src="images/banana.gif" alt="Banana Time!">
if(HTML_NAME.compare("report/index.html") == 0){
hout<<"<img src="<<'"'<<"images/banana.gif"<<'"'<<" alt="<<'"'<<"Banana Time!"<<'"'<<'>'<<endl;
}
else if(HTML_NAME.compare("report/index2.html") == 0){
hout<<"<img src="<<'"'<<"images/banana.gif"<<'"'<<" alt="<<'"'<<"Banana Time!"<<'"'<<'>'<<endl;
}
else if(HTML_NAME.compare("report/index3.html") == 0){
hout<<"<img src="<<'"'<<"images/banana.gif"<<'"'<<" alt="<<'"'<<"Banana Time!"<<'"'<<'>'<<endl;
}
else{
//hout<<"<img src="<<'"'<<"../images/banana.gif"<<'"'<<" alt="<<'"'<<"Banana Time!"<<'"'<<'>'<<endl;
}
//body and html end
hout<<"</body>"<<endl<<"</html>"<<endl;
}

