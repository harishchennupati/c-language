class myfame{
    constructor(){
        this.name="hello"
    }
    function m(){

        return this.name
    }
}

var s=new myfame()

console.log(s.m())
