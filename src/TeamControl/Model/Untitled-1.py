#! /usr/bin/python3
#   
if __name__ == '__main__':
    result = ''
    for i in [
            "field", "calib", "models"
   ]:
        result += f"""
    @property
    def {i}(self):
        return self._{i}

    @{i}.setter
    def {i}(self, {i}):
        if not isinstance({i}, 1111):
            log.error()
        self._{i} = {i}\n"""
        
    print(result)