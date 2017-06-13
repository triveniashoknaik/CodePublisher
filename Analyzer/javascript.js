function minmax(instance, id) {
    if (instance.innerHTML == '-') {
        instance.innerHTML = '+';
        document.getElementById(id).style.display = 'none';
    }
    else {
        instance.innerHTML = '-';
        document.getElementById(id).style.display = 'block';
    }
}

