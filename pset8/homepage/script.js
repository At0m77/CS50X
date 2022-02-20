
// HERE I CAN CHECK USING THE PAGE 'HREF' FOR EVERY PAGE
// I CAN ALSO DO THE SAME USING A PAGE CLASS
// document.addEventListener('DOMContentLoaded', function(){
//     var e = window.location.href;

//     if(window.location.pathname == '/message.html'){
//         $("#message").addClass("active");
//     }
//     else if(window.location.pathname == '/projects.html'){
//         $("#projects").addClass("active");
//     }
// });


// HERE IS A TEST TO SEE IF I CAN ADD EVENT HANDLER TO WORK WITH MY ANCHORS, 
// SO, I DON'T NEED TO ADD SO MANY CONDITIONS
// function trigger (event){
//     document.addEventListener('DomContentLoaded', lightUp(event));
// }


// function lightUp(event){
// var e = event.srcElement.id;
// $("#"+e).addClass("active");
// }

//change the mesage me box color
$(document).ready(function(){
    $("#message").addClass("active");
});


function alertfn(){
    let name = $("#name").val();
    alert("Hello "+ name + "\nSorry but I don't accept message requests yet.")
}

