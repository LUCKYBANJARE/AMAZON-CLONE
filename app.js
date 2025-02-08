const express=require('express');
const http=require("http");
const socket=require("socket.io");
const { Chess }=require("chess.js");

const app=express();
const server=http.createServer(app);
const io=socket(server);
const path=require("path");

app.set("view engine","ejs");
app.use(express.static(path.join(__dirname,"public")));

const chess=new Chess();
let players={};
let currentPlayer="w";

app.get("/",(req,res)=>{
    res.render("index",{title : "Chess Game"});
});

io.on("connection",function(uniquesocket){
    console.log("connected");
    // uniquesocket.on("disconnect",function(){
    //     // console.log("Helloo received");
    //     // io.emit("Accept My Grettings");
    //     console.log("Disconnected");
    // })
    if(!players.white){
        players.white=uniquesocket.id;
        uniquesocket.emit("playerRole","w");
    }else if(!players.black){
        players.black=uniquesocket.id;
        uniquesocket.emit("playerRole","b");
    }else{
        uniquesocket.emit("spectatorRole");
    }
    uniquesocket.on("disconnect",function(){
        if(uniquesocket.id===players.white){
            delete players.white;
        }else if(uniquesocket.id===players.black){
            delete players.black;
        }else{

        }
    });
    uniquesocket.on("move",(move)=>{
        try{
            if(chess.turn()==='w' && uniquesocket.id!==players.white) return;
            if(chess.turn()==='b' && uniquesocket.id!==players.black) return;
            const result=chess.move(move);
            if(result){
                currentPlayer=chess.turn();
                io.emit("move",move);
                io.emit("boardState",chess.fen());
            }else{
                console.log("Invalid move :",move);
                uniquesocket.emit("InvalidMove",move);
            }
            

        }catch(err){
            console.log(err);
            uniquesocket.emit("Invalid move :",move);
        }

    })
});

server.listen(3000,function(){
    console.log("listening port 3000");
});