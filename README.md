# React-Component-Creator v1.1
Simple C++ program to create React Component Template File. Tested only on Ubuntu.

Usage:

1: Compile using your C++ compiler of choice.
2: createComponent <Name> <DIRECTORY>

- The default directory used is ./src/components
- Names must start with an uppercase letter
- The program creates a directory with the same name as the component and creates a file inside named "index.js".

Example:

$ createComponent MyReactComponent ./
$ cat MyReactComponent/index.js

import React from 'react'

class MyReactComponent extends React.Component{
	constructor(props){
		super(props);
		this.state={}
	}

	render(){
		return(<div> MyComponent </div>)
	}
}
