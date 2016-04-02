function focus_(){
		var text=document.getElementById("text");
		text.style.display="none";
}

function blur_(){
		var text=document.getElementById("text");
		text.style.display="block";
}

function click_(obj){
		var parent=obj.parentNode.parentNode.parentNode;
		var parent_=obj.parentNode.parentNode;
		parent_.innerHTML="";
		parent_.className="box_";
		parent.removeChild(parent_);
		var div_=document.createElement("div");
		div_.className="box_";
		parent.appendChild(div_);
}